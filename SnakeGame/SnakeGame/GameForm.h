#pragma once

#include <time.h>
#include <stdlib.h>

namespace SnakeGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// —водка дл€ GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}

		virtual void OnPaint(System::Object^ obj, PaintEventArgs^ e) override {
			Graphics^ g = e->Graphics;

			Brush^ fruitBrush = gcnew SolidBrush(Color::Red);
			g->FillRectangle(fruitBrush, fruitPosition.X, fruitPosition.Y, BLOCKSIZE, BLOCKSIZE);

			Brush^ snakeBrush = gcnew SolidBrush(Color::Green);
			for each(Point el in snake)
				g->FillRectangle(snakeBrush, el.X, el.Y, BLOCKSIZE, BLOCKSIZE);
		}

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		List<Point>^ snake;
		Point fruitPosition;
		const int BLOCKSIZE = 20;

		int fruitCount = 0;
		Label^ scoreLabel;

		Timer^ timer;
		int moveX = 0, moveY = 0;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(600,600);
			this->Text = L"Snake Game";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = Color::Black;
			this->ResumeLayout(false);

			scoreLabel = gcnew Label();
			scoreLabel->ForeColor = Color::White;
			scoreLabel->BackColor = Color::Transparent;
			scoreLabel->Text = "Score: 0";
			scoreLabel->Location = Point(10, 10);
			this->Controls->Add(scoreLabel);

			snake = gcnew List<Point>();
			snake->Add(Point(300, 300));
			srand(time(NULL));
			PlaceFruit();

			timer = gcnew Timer();
			timer->Interval = 180;
			timer->Tick += gcnew EventHandler(this, &GameForm::OnTimerTick);
			timer->Start();

			this->Paint += gcnew PaintEventHandler(this, &GameForm::OnPaint);
			this->KeyDown += gcnew KeyEventHandler(this, &GameForm::OnKeyDown);
		}
#pragma endregion

		void PlaceFruit() {
			int maxX = this->ClientSize.Width / BLOCKSIZE;
			int maxY = this->ClientSize.Height / BLOCKSIZE;

			do {
				fruitPosition = Point(rand() % maxX * BLOCKSIZE, rand() % maxY * BLOCKSIZE);
			} while (snake->Contains(fruitPosition));
		}

		void OnTimerTick(Object^ obj, EventArgs^ e) {
			MoveSnake();

			if (snake[0].X < 0 || snake[0].Y < 0 || snake[0].X > this->ClientSize.Width || snake[0].Y > this->ClientSize.Height) {
				timer->Stop();
				MessageBox::Show("Game Over");
				return;
			}

			if (snake->Count >= 4) {
				for (int i = 1; i < snake->Count; i++) {
					if (snake[0] == snake[i]) {
						timer->Stop();
						MessageBox::Show("Game Over. You ate yourself!");;
						return;
					}
				}
			}

			if (snake[0] == fruitPosition) {
				fruitCount++;
				scoreLabel->Text = "Score: " + fruitCount.ToString();
				GrowthSnake();
				PlaceFruit();
			}

			this->Invalidate();
		}

		void MoveSnake() {
			Point newHead = snake[0];

			newHead.X += moveX * BLOCKSIZE;
			newHead.Y += moveY * BLOCKSIZE;
			snake->Insert(0, newHead);
			snake->RemoveAt(snake->Count - 1);
		}

		void GrowthSnake() {
			Point newHead = snake[0];

			newHead.X += moveX * BLOCKSIZE;
			newHead.Y += moveY * BLOCKSIZE;
			snake->Insert(0, newHead);
		}

		void OnKeyDown(Object^ obj, KeyEventArgs^ e) {
			switch (e->KeyCode) {
			case Keys::Up:
				moveX = 0;
				moveY = -1;
				break;
			case Keys::Down:
				moveX = 0;
				moveY = 1;
				break;
			case Keys::Left:
				moveX = -1;
				moveY = 0;
				break;
			case Keys::Right:
				moveX = 1;
				moveY = 0;
				break;
			}
			
		}
	};
}

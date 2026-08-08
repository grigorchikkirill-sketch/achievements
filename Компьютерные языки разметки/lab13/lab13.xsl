<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <html>
      <head>
        <style>
          table {
            width: 60%;
            border: 1px solid black;
            border-collapse: collapse;
            margin: 20px;
          }

          th,
          td {
            border: 1px solid black;
            padding: 8px;
            text-align: center;
          }

          th {
            background-color: orange;
            font-weight: bold;
          }
        </style>
        <title>task1</title>
      </head>
      <body>
        <table>
          <tr>
            <th><xsl:value-of select="container/info/product" /></th>
            <th><xsl:value-of select="container/info/price" /></th>
            <th><xsl:value-of select="container/info/opisanie" /></th>
          </tr>
          <xsl:for-each select="container/tovar">
            <xsl:sort select="value" data-type="number" order="descending" />
            <tr>
              <td><xsl:value-of select="name" /></td>
              <td><xsl:value-of select="value" /></td>
              <td><xsl:value-of select="description" /></td>
            </tr>
          </xsl:for-each>
        </table>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>
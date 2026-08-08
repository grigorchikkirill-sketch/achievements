<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <html>
      <head>
        <style>
          table {
            width: 80%;
            border: 1px solid black;
            border-collapse: collapse;
            margin: 20px;
          }
          th, td {
            border: 1px solid black;
            padding: 8px;
            text-align: center;
          }
          th {
            background-color: orange;
            font-weight: bold;
          }
          .min {
            background-color: red;

          }
          .max {
            background-color: green;
       
          }
        </style>
        <title>task2</title>
      </head>
      <body>
        <table>
          <tr>
            <th>Students</th>
            <th>Grade</th>
          </tr>
          <xsl:for-each select="container/student">
            <xsl:apply-templates select="."/>
          </xsl:for-each>
        </table>
      </body>
    </html>
  </xsl:template>

  <xsl:template match="student">
    <tr>
      <td><xsl:value-of select="name"/></td>
      <xsl:choose>
        <xsl:when test="value &lt; 4">
          <td class="min"><xsl:value-of select="value"/></td>
        </xsl:when>
        <xsl:when test="value &gt; 8">
          <td class="max"><xsl:value-of select="value"/></td>
        </xsl:when>
        <xsl:otherwise>
          <td><xsl:value-of select="value"/></td>
        </xsl:otherwise>
      </xsl:choose>
    </tr>
  </xsl:template>
</xsl:stylesheet>
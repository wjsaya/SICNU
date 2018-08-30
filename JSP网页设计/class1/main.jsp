<%@ page pageEncoding="UTF-8"%>
<html>
    <head>
           <title>jsp输出乘法表</title>
    </head>
    <body>
        <p>直接输出：</p>
           <%
            for(int y=1; y<10; y++) {
                for(int x=1; x<=y; x++) {
                //    out.println(y + "X" + x + "=" + y*x);
                    out.print(y);
                    out.print("X");
                    out.print(x);
                    out.print("=");
                    out.print("<font color='red'>" + y*x + "</font>");
                    out.print("\t");
                }
                out.println("<br>");
            }
           %>


        <p>表格输出：</p>
        <table border=1 cellspacing=0 frame=none>
        <!-- border：分割线大小 !-->
        <!-- cellspacing：表格间距 !-->
        <!-- frame：表格外边框显示模式 !-->
            <% for(int y=1; y<10; y++) { %>
            <tr>
                <% for(int x=1; x<=y; x++) { %>
                    <td>
                     <%
                        out.print(y);
                        out.print("X");
                        out.print(x);
                        out.print("=");
                        out.print("<font color='red'>" + y*x + "</font>");
                    %>
                    </td>
                <% } %>
            <% } %>
            </tr>
       </table>
    </body>
</html>

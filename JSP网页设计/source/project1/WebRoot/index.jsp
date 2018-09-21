<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>9*9乘法表</title>
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->
  </head>
  
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
</html>

<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>底部</title>
  </head>
  
  <body>
  
  <table border=1 align="center" width="660" height="100" style="background-color:orange">
  	<tr>
  		<td  align="center">
  			地址：中华人民共和国 四川省 成都市<br>
  			四川师范大学 电话：028-84683033 84683099 传真：028-84683099<br>
			Copyright ? 2008 Sichuan Urban Voctional College All Rights Reserved<br>
			蜀ICP备09042873号
  		</td>
  	</tr>  
  </table>
  
  </body>
</html>

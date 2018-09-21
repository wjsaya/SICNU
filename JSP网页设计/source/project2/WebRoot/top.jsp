<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>导航</title>
  </head>
  
  <body>
  
  <table border=1 align="center" width="650px">
  	<tr>
  		<td>
			<img src="./pic/top.jpg"/>
  		</td>
  	</tr>
  	
  	<tr>
  		<td>
  		<marquee>欢迎光临ebook购书中心</marquee>
  		</td>
  	</tr>
  
  </table>
  
  </body>
</html>

<%@ page language="java" import="java.util.*" pageEncoding="ytf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>导航</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  <body>
	<table>
		<thead>
			<tr>
				<td>地址</td>
				<td>说明</td>
			</tr>
		</thead>
		<tbody>
			<tr>
				<td>
					<a href="./project1">9*9乘法表</a>
				</td>
				<td>
					9*9乘法表
				</td>
			</tr>
			<tr>
				<td>
					<a href="./project2">project2</a>
				</td>
				<td>
					page_include使用练习
				</td>
			</tr>
			<tr>
				<td>
					<a href="./project3">project3</a>
				</td>
				<td>
					网页计算器，用到response对象以及jsp_forward等
				</td>
			</tr>
		</tbody>
		
	
	</table>



  </body>
</html>

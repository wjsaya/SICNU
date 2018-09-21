<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>计算器</title>
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
  
  <% String re = request.getParameter("re"); %>
		
	<form style="text-align: center" action="counter.jsp" method="post">
		<input type="text" name="num1"/>
		<select name="sw">
			<option value='1'>+</option>
			<option value='2'>-</option>
			<option value='3'>*</option>
			<option value='4'>/</option>
			<option value='5'>%</option>
		</select>
		<input type="text" name="num2"/>
		<button>=</button>
		<input type="text" value="<%=re %>"/>
		
		
	</form>
	


  </body>
</html>

<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>

<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>结果页面</title>
    
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
	<%
		String num1 = request.getParameter("num1"); 
		String num2 = request.getParameter("num2");
		String sw = request.getParameter("sw"); 
		project3.func a = new project3.func();
		String re = a.counter(num1, num2, sw);
		
		out.print(re);
	%>
	
	<jsp:forward page="index.jsp">
		  <jsp:param name="re" value="<%=re %>"/>
	</jsp:forward>
	
  </body>
</html>

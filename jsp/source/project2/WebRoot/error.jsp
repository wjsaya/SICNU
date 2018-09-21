<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>报错</title>
  </head>
  
  <body>
	  
  	<jsp:include page="top.jsp"></jsp:include>
  	
	  <div style="text-align:center; height:200">
	  
		<p>今日访问人数已达上限， 请明日访问 </p>
		<a href="./index.jsp">重置访客人数</a>
		
		<form action="index.jsp" method="post">
			<input name="countNum" type="hidden" value="0"/>
			<button type="submit">清空</button>
		</form>

	  </div>
	 

  	<jsp:include page="bottom.jsp"></jsp:include>
	  
  </body>
</html>


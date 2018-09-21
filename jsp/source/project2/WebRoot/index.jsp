<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>

<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>首页</title>
  </head>
  
  <body>
  
  	<jsp:include page="top.jsp"></jsp:include>
  	
  	<div style="text-align:center">
  		<img  width=600px src="./pic/main.jpg" />
  	</div>
  	
  	<%  
  		try {
  	 	int n = Integer.valueOf(request.getParameter("countNum"));
  	 %>
  	<jsp:include page="counter.jsp">
	   		<jsp:param value="<%=n %>" name="countNum"/>
  	</jsp:include>
  	 	
  	 <%
  	 	}
  	 	catch (Exception e) {
  	 %>
  			<jsp:include page="counter.jsp"></jsp:include>
  		<% } %>

  	<jsp:include page="bottom.jsp"></jsp:include>
  	

  	
  </body>
</html>

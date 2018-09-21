<%@page import="org.omg.CORBA.Request"%>
<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>


<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>计数器</title>
  </head>
  
  <body>
  	<%!int n=0;	%>
  	<% 
  		try {
  	 	n = Integer.valueOf(request.getParameter("countNum"));
  	 	}
  	 	catch (Exception e) {
  			n += 1; 
  		}
  	%>
  	
  	<div style="text-align:center">
  		您是第
	  		
	  	<% if (n > 25) { %>
	  		<jsp:forward page="error.jsp"></jsp:forward>
	  		
	  	<% } else {
	  		String nlist = "" + n;
			for(int i=0; i<nlist.length(); i++) {
				char c = nlist.charAt(i);
				out.print("<img src=\"./pic/luobo/" + c + ".gif\">");	
		   	 }
		   } %>
		   
  		位访问本站的用户
   	</div>
  	
  </body>
</html>






<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@page import="javax.xml.ws.Response"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>提交结果</title>
    
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
		request.setCharacterEncoding("utf-8");
		String vcode = request.getParameter("vcode");
		String vcodeinput = request.getParameter("vcodeinput");
		if (!vcode.equals(vcodeinput)) {
	%>
		<jsp:forward page="index.jsp"></jsp:forward>
	<%
		}
		
		String name = request.getParameter("name");
		String age = request.getParameter("age");
		String degree = request.getParameter("degree");
		String email = request.getParameter("email");
		String[] hobby = request.getParameterValues("hobby");
		String reply = request.getParameter("reply");
		String extra = request.getParameter("extra");
		String verCode = request.getParameter("verCode");
		
		switch (Integer.valueOf(reply)) {
			case 1:
				reply = "好";
				break;
			case 2:
				reply = "一般";
				break;
			case 3:
				reply = "差";
				break;
			default:
				reply = "";
				break;
		}
		
		switch (Integer.valueOf(degree)) {
			case 1:
				degree = "高中";
				break;
			case 2:
				degree = "专科";
				break;
			case 3:
				degree = "本科";
				break;
			case 4:
				degree = "研究生";
				break;
			default:
				reply = "";
				break;
	
		}
	%>

	<br>用户名：<%=name %>
	<br>年龄：<%=age %>
	<br>学历：<%=degree %>
	<br>email：<%=email %>
	<br>爱好：
	<%
		for(int i=0; i<hobby.length; i++) {
			out.print(hobby[i] + "&nbsp;");
		}
	%>
	<br>对本站的评价：<%=reply %>
	<br>其他信息：
	<br/><textarea name="extra" rows="5" cols="40"><%=extra %></textarea>
		
	<br>验证码：<%=verCode %>
  </body>
</html>

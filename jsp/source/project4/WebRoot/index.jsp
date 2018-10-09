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

	<form action="result.jsp" method="post">
		
		<br/>姓名：<input name="name"/>
		<br/>年龄：<input name="age"/>
		<br/>学历：
		<select name="degree">
			<option value="1">高中</option>
			<option value="2">专科</option>
			<option value="3">本科</option>
			<option value="4">研究生</option>
		</select> <br/>
		<br/>Email：<input name="email"/>
		<br/>爱好：<br/>
		<input type="checkbox" name="hobby" value="运动"/>运动
		<input type="checkbox" name="hobby" value="旅游"/>旅游
		<input type="checkbox" name="hobby" value="服装"/>服装<br/>
		<input type="checkbox" name="hobby" value="阅读"/>阅读
		<input type="checkbox" name="hobby" value="音乐"/>音乐
		<input type="checkbox" name="hobby" value="购物"/>购物<br/>
		
		<br/>对本站的评价：<br/>
		<input type="radio" name="reply" value="1"/>好
		<input type="radio" name="reply" value="2"/>一般
		<input type="radio" name="reply" value="3"/>差
		
		<br/>其他信息：<br/>
		<textarea name="extra" rows="5" cols="40"></textarea>
	
		<br/>验证码
		<input name="vcodeinput" />
		<%!String vcode = ""; %>
		<%
		vcode = "";
		for(int i=0; i<4; i++) {
			String temp = "";
			Random rand = new Random();
			if(rand.nextBoolean()) {
			//true,数字
			temp = String.valueOf(rand.nextInt(10));
				out.print("<img width=25 src=./pic/" + temp + ".gif>");
			}
			else {
			//false,字母
			temp = String.valueOf((char)(97 + rand.nextInt(26)));		
				out.print("<img width=25 src=./pic/" + temp + ".gif>");
			}
			vcode += temp;
		}
				out.print(vcode);
		
		%>
		
		<br/>
		<input type="hidden" value=<%=vcode %> name="vcode"/>
		<input type="submit" text="提交"/>
		<input type="reset" text="重置"/>
	</form>
  </body>
</html>

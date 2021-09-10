# 查询语句指令

```apl
; 创建数据库
vap db, 0
alloc &db, "mydb"

; 创建表
vap tab, 1
alloc &tab, "t_user"

; 创建表字段
beg *tab:

	vap col_0:
	    mov "username"
	    mov varchar
	    mov 255
	    mov not null
	end:add
	
	vap col_1:
	    mov "password"
	    mov varchar
	    mov 255
	    mov not null
	end:add
	
	vap col_2:
	    mov "age"
	    mov int
	    mov 3
	    mov not null
	end:add
	
end

add &db, &tab ; 将表添加到数据库
```


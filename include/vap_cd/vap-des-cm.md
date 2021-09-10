# 查询语句指令

## 创建数据库&表：

```clojure
; 创建数据库
vap vp0, 0x0
aoc &vp0, "mydb"

; 创建表
vap vp1, 0x1
aoc &vp1, "t_user"

; 创建表字段
beg *v1:

	vap 0x2:
	    mov "username"
	    mov varchar
	    mov 255
	    mov false
	end:add
	
	vap 0x2:
	    mov "password"
	    mov varchar
	    mov 255
	    mov false
	end:add
	
	vap 0x2:
	    mov "age"
	    mov int
	    mov 3
	    mov true ; 是否允许为空
	end:add
	
end

add &vp0, &vp1 ; 将表添加到数据库
```

## 简单的查询

> select * from t_user

```clojure
vap vp0, 0x1
get &vp0, "mydb/t_user"

get &vp0, all
```

## 简单的修改

> ALTER TABLE t_user MODIFY name varchar(255);

```clojure
vap vp0, 0x1
get &vp0, "mydb/t_user"

vap vp1, 0x2
get &vp1, &vp0["name"]

mod &vp1, 0, "name"
mod &vp1, 1, varchar
mod &vp1, 2, 255
```
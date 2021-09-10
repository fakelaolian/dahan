# 查询语句指令

## 内置函数以及类型和关键字

| 关键字  | 说明                                      |
| ------- | ----------------------------------------- |
| 0x0     | 数据库类型，一般用于mov, get, vap等地方   |
| 0x1     | 表类型，作用同上                          |
| 0x2     | 字段类型                                  |
| all     | 代表所有，如果是get指令，代表查询所有匹配 |
| varchar | 字段类型                                  |
|         |                                           |
|         |                                           |
|         |                                           |
|         |                                           |



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
get &vp1, &vp0["name"] ; &vp0["name"] 表示从vp0指针中获取name表

mod &vp1, 0, "name"
mod &vp1, 1, varchar
mod &vp1, 2, 255
```


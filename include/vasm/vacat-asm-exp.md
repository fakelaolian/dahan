# 查询语句指令

## 内置函数以及类型和关键字

| 关键字  | 说明                                      |
| ------- | ----------------------------------------- |
| base     | 数据库类型，一般用于mov, get, va等地方   |
| tab     | 表类型，作用同上                          |
| col     | 字段类型                                  |
| all     | 代表所有，如果是get指令，代表查询所有匹配 |
| varchar | 字段类型                                  |
|         |                                           |
|         |                                           |
|         |                                           |
|         |                                           |

## 创建数据库&表：

```clojure
; 创建数据库
va vp0, base
aoc &vp0, "mydb"

; 创建表
va vp1, tab
aoc &vp1, "t_user"

; 创建表字段
beg *v1:

	va col:
	    mov "username"
	    mov varchar
	    mov 255
	    mov false
	end:add
	
	va col:
	    mov "password"
	    mov varchar
	    mov 255
	    mov false
	end:add
	
	va col:
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
va vp0, tab
get &vp0, "mydb/t_user"

get &vp0, all
```

## 简单的修改

> ALTER TABLE t_user MODIFY name varchar(255);

```clojure
va vp0, tab
get &vp0, "mydb/t_user"

va vp1, col
get &vp1, &vp0["name"] ; &vp0["name"] 表示从vp0指针中获取name表

mod &vp1, 0, "name"
mod &vp1, 1, varchar
mod &vp1, 2, 255
```

## 条件查询

> select * from t_user where name = '张三'

```clojure
va vp0, tab
get &vp0, "mydb/t_user"

```


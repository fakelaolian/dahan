# 查询语句指令

## 内置函数以及类型和关键字

| 关键字  | 说明                                      |
| ------- | ----------------------------------------- |
| 0x0     | 数据库类型，一般用于mov, get, lvap等地方   |
| 0x1     | 表类型，作用同上                          |
| 0x2     | 字段类型                                  |
| 0x3     | 条件指针                                  |
| all     | 代表所有，如果是get指令，代表查询所有匹配 |
| lmt     | 和all比较相似，只不过这个是分页           |
| varchar | 字段类型                                  |
|         |                                           |
|         |                                           |

## 创建数据库&表：

```clojure
; 创建数据库
lvap vp0, 0x0
aoc &vp0, "mydb"

; 创建表
lvap vp1, 0x1
aoc &vp1, "t_user"

; 创建表字段
beg *v1:

	lvap 0x2:
	    mov "username"
	    mov varchar
	    mov 255
	    mov false
	end:add
	
	lvap 0x2:
	    mov "password"
	    mov varchar
	    mov 255
	    mov false
	end:add
	
	lvap 0x2:
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
lvap vp0, 0x1
get &vp0, "mydb/t_user"

get &vp0, null, all
```

## 简单的修改

> ALTER TABLE t_user MODIFY name varchar(255);

```clojure
lvap vp0, 0x1
get &vp0, "mydb/t_user"

lvap vp1, 0x2
get &vp1, &vp0["name"] ; &vp0["name"] 表示从vp0指针中获取name表

mod &vp1, 0, "name"
mod &vp1, 1, varchar
mod &vp1, 2, 255
```

## 条件查询

> select * from t_user where name = '张三' and age > 18 limit 0, 10

```clojure
lvap vp0, 0x1
get &vp0, "mydb/t_user"

lvap vp1, 0x3
beg *vp1:
    ifeq "name", "张三"
    ifge "age", 18    
end

get &vp0, &vp1, lmt[0:10] ; 如果不需要分页就传入all
```

## 关联查询

> select * from t_user a left join t_user2 b on a.name = b.name where a.age > 18

```clojure
lvap vp0, 0x1
lvap vp1, 0x1
get &vp0, "mydb/t_user"
get &vp1, "mydb/t_user2"

lvap vp2, 0x3
beg *vp2:
	ifeq &vp0, &vp1, "name"
end

join &vp1, &vp0, &vp2

```


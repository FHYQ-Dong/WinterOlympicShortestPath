1、在 Carroute.xlsx 中将图片上所画的路线整理到 xlsx 文档中，
    共有 3 个 sheet， 分别为 BeiJing、YanQing、ZhangJiaKou.
    每个单元格中有两个数据，
    第一个为 从左边对应地点到上边对应地点的时间；
    第二个为 从上边对应地点到左边对应地点的时间.
    即 1->1' 与 1'->1.
2、以 .carroute 结尾的文件中保存了三个地区的路线的抽象描述，
    其格式为：
    第一行，三个整数，分别为总共节点数、总共边数，目的地数量；
    第二行，多个整数，为具体的目的地；
    余下多行：
    每行表示一条单向边，一行中三个数分别表示 起点、终点、边权.
    其中 起点、终点、目的地 由每个地点的 ID 表示，可在 Carroute.xlsx 中查询.
3、carroute.cpp 为 C++ 源文件，包含求最短路的代码，
    carroute.exe 为由该源文件经编译后形成的可执行文件.
4、采取 Dijkstra 算法求由节点 1 到其余各节点的最短路.
    分别获取 BeiJing.carroute、YanQing.carroute、ZhangJiaKou.carroute 中的数据，
    将结果输出到 BeiJing.shortestpath、YanQing.shortestpath、ZhangJiaKou.shortestpath 之中，
    分为 GO、BACK 两部分，
    每个部分的格式为：
    每行表示一条数据，一行中有多个数
    其格式为：
    目的地，总边权，路线
    其中 终点、路径中的地点 由其 ID 表示，可在 Carroute.xlsx 中查询.
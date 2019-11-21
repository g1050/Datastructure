#include "matrix.h" 
using std::cout;
using std::cin;
using std::endl;
void Matrix::printMenu()
{
    std::cout << "[1]矩阵加法\n";
    std::cout << "[2]矩阵减法\n";
    std::cout << "[3]矩乘乘法\n";
    std::cout << "[4]矩阵逆置\n";
    std::cout << "[0]退出\n";
}

void Matrix::reverse()
{
    TSMATRIX in;
    cout << "请输入矩阵:" << endl;
    inputMatrix(in);
    cout << "\n\n----------------------------\n"; 
    PrintMatrix(in);
    cout << "----------------------------\n\n"; 
    
    for(int i = 0;i<in.nums;i++){
        std::swap(in.data[i].col,in.data[i].row);
    }
    
    cout << "\n\n----------------------------\n"; 
    PrintMatrix(in);
    cout << "----------------------------\n\n"; 
    return ;
}
void Matrix::sub()
{
    int k = 0;
    cout << "请输入第一个矩阵:" << endl;
    inputMatrix(m1);
    cout << "请输入第二个矩阵:" << endl;
    inputMatrix(m2);
    if(m1.row != m2.row || m1.col != m2.col){
        cout << "输入的两个矩阵不能相减法" << endl;
        return ;
    }

    //将两个矩阵相加结果保存在res三元组中
    for(int i = 1;i<=m1.row;i++){
        for(int j = 1;j<=m1.col;j++){
            int res = findElement(m1,i,j) - findElement(m2,i,j);        
            if(res > 0){
                this->res.data[k].row = i;
                this->res.data[k].col = j;
                this->res.data[k].value = res;
                k++;
            }
        }
    }
    this->res.row = m1.row;
    this->res.col = m1.col;
    this->res.nums = k;

    /* cout << this->res.row << " " << this->res.col << " " << this->res.nums << endl; */
    cout << "\n\n----------------------------\n"; 
    PrintMatrix(this->res);
    cout << "----------------------------\n\n"; 
    return ;
}

void Matrix::plus()
{
    int k = 0;
    cout << "请输入第一个矩阵:" << endl;
    inputMatrix(m1);
    cout << "请输入第二个矩阵:" << endl;
    inputMatrix(m2);
    if(m1.row != m2.row || m1.col != m2.col){
        cout << "输入的两个矩阵不能相加" << endl;
        return ;
    }

    //将两个矩阵相加结果保存在res三元组中
    for(int i = 1;i<=m1.row;i++){
        for(int j = 1;j<=m1.col;j++){
            int res = findElement(m1,i,j) + findElement(m2,i,j);        
            if(res > 0){
                this->res.data[k].row = i;
                this->res.data[k].col = j;
                this->res.data[k].value = res;
                k++;
            }
        }
    }
    this->res.row = m1.row;
    this->res.col = m1.col;
    this->res.nums = k;

    /* cout << this->res.row << " " << this->res.col << " " << this->res.nums << endl; */
    cout << "\n\n----------------------------\n"; 
    PrintMatrix(this->res);
    cout << "----------------------------\n\n"; 
    return ;
}


int Matrix::findElement(TSMATRIX &in,int row,int col)
{
    for(int i = 0;i<in.nums;i++){
        if(in.data[i].row == row && in.data[i].col == col ){
            return in.data[i].value;
        }
    }
    return 0;
}

void Matrix::PrintMatrix(TSMATRIX &ma)
{
    if(ma.nums == 0){
        cout << "0" << endl;
        return ;
    }
    for(int i = 1;i<=ma.row;i++){
        for(int j = 1;j<=ma.col;j++){
            cout << findElement(ma,i,j) << " ";
        }
        cout << "\n";
    }
    return ;

}

void Matrix::mul()
{
    int k = 0;

    cout << "请输入第一个矩阵" << endl;
    inputMatrix(m1);
    cout << "请输入第二个矩阵" << endl;
    inputMatrix(m2);

    /* PrintMatrix(m1); */
    /* cout << "----\n" ; */
    /* PrintMatrix(m2); */
    /* cout << "----\n" ; */
    
    if(m1.col != m2.row){
        cout << "输入的两个矩阵不能矩阵!" << endl;
        return ;
    }

    for(int i = 1;i<=m1.row;i++){
        for(int q = 1;q<=m2.col;q++){
            int res = 0;
            for(int j = 1;j<=m1.col;j++){
                /* cout << i << " " << j << endl; */
                /* cout << j << " " << q << endl; */
                res += findElement(m1,i,j) *  findElement(m2,j,q);
            }
            if(res > 0){
                this->res.data[k].row = i;
                this->res.data[k].col = q;
                this->res.data[k].value = res;
                k++;
            }
        }
    }


    this->res.row = m1.row;
    this->res.col = m1.col;
    this->res.nums = k;
    
    cout << "\n\n----------------------------\n"; 
    PrintMatrix(this->res);
    cout << "----------------------------\n\n"; 
}
void Matrix::inputMatrix(TSMATRIX &in)
{
    cout << "矩阵行数:";
    cin >> in.row;
    cout << "矩阵列数";
    cin >> in.col;

    int k = 0; 
    while(k < in.row*in.col){
        cout << "以三元组形式输入矩阵(row,col,value),输入0 0 0退出 ";
        cin >> in.data[k].row >> in.data[k].col >> in.data[k].value;
        if(!in.data[k].row && !in.data[k].col && !in.data[k].value){
            k++;
            break;
        }
        k++;
    }

    in.nums = k;
    /* cout << "********************\n"; */
    /* PrintMatrix(in); */
    /* cout << "********************\n"; */
    return ;
}

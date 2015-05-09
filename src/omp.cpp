/** Orthogonal matching pursuit
* x: input signal, N * 1 
* D: dictionary, N * M 
* L: number of non_zero elements in output
* coeff: coefficent of each atoms in dictionary, M * 1
*/
void OMP(const cv::Mat_<double>& x, const cv::Mat_<double>& D, int L, cv::Mat_<double>& coeff){
    int dim = x.rows;
    int atom_num = D.cols;
    coeff = Mat::zeros(atom_num, 1, CV_64FC1);
    Mat_<double> residual = x.clone();
    Mat_<double> selected_index(L, 1);
    Mat_<double> a;
    for (int i = 0; i < L; i++){
        cout << "here ok 1" << endl;
        Mat_<double> dot_p = D.t() * residual; 
        Point max_index;
        minMaxLoc(abs(dot_p), NULL, NULL, NULL, &max_index);
        int max_row = max_index.y;
        selected_index(i) = max_row;
        Mat_<double> temp(dim, i + 1);
        for (int j = 0; j < i + 1; j++){
            D.col(selected_index(j)).copyTo(temp.col(j));
        }
        Mat_<double> invert_temp;
        invert(temp, invert_temp, CV_SVD);
        a = invert_temp * x;
        residual = x - temp * a;
    }

    for (int i = 0; i < L; i++){
        coeff(selected_index(i)) = a(i);
    }
} 
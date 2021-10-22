    if(code != '\n')
        printf("mode >>> ");
    scanf("%c", &code);
    switch(code)
    {
        case 'a':   // 四則演算で初期化
            printf("arithmetic mode\n");
            printf(">>> ");
            scanf("%s", &inputnum[0]);  // 初期値の入力
            switch(inputnum[0])
            {
                case 'a':
                    printh("既に四則演算モードです。\n");
                    break;
                case 'f':
            }
            resultbuf = atof(inputnum); // 初期値の入力
            result = 0 + resultbuf; // 結果の値の初期化
            arithmeticmode = true;
            init = false;   // 初期化に成功
            break;
        case 'f':   // 関数で初期化
            printf("functional mode\n");
            printf(">>> ");
            scanf("%c", &code);
            if(code == '\n')
            {
                init = true; // 初期化に失敗
                break; // switch(code) case 'f' break
            }
            scanf("%c", &function);
            if(code == '\n')
            {
                init = true; // 初期化に失敗
                break; // switch(code) case 'f' break
            }
            scanf("%s", &inputnum[0]);
            resultbuf = (atof(inputnum) * M_PI / 180);
            switch(function)
            {
                case 's':
                case 'S':
                    result = (code == '-') ? sin(resultbuf) * -1 : sin(resultbuf);
                    break;
                case 'c':
                case 'C':
                    result = (code == '-') ? cos(resultbuf) * -1 : cos(resultbuf);
                    break;
                case 't':
                case 'T':
                    result = (code == '-') ? tan(resultbuf) * -1 : tan(resultbuf);
                    break;
            }
            arithmeticmode = false;
            init = false;   // 初期化に成功
            break;  // case 'f' break
        case '?':
            printh(MODESELECT);
            break;
        default:   // switch(code) default
            init = printh(ERROR);   // 初期化に失敗
            break;  // default '\n' break


///////////////////////////////////////////////////////////////////////////

/*** おまけ関数 ***/
#if OMAKE
// 未完成
void make()
{
    /*
    ///    FILE *fopen(const char *filename, const char *mode);
    ///    *mode は "a+" を指定することで ファイルの読み書きが可能。ファイルが存在しない場合は作成し、ファイルが存在する場合はファイルの末尾に文章を追加するモードで開く。
    char filename[1024] = "繧ｳ繝槭Φ繝峨�繝ｭ繝ｳ繝励ヨ繧堤┌髯舌↓陦ｨ遉ｺ縺輔○繧九□縺代�繝励Ο繧ｰ繝ｩ繝�縲�.bat"   // filename
    FILE *file;// FILE is defined in stdio.h as structure.
    file = fopen(filename, "a+");
    fprintf("@echo off\n");
    fprintf("setlocal\n");
    fprintf("cmd\n");
    fprintf("endlocal\n");
    while(1)
    {
    }
    fclose(file);
    */
}

// 未完成
void malware()
{
    char input[16];

    while(1)
    {
        printf("今からこのコンピュータにウィルスを作成します。\nよろしいですか？[Y/N] ");
        printf(">>> ");
        scanf("%s", &input[0]);
        switch(input[0])
        {
            case 'Y':
            case 'y':
                printf("あなたには度胸があります。\n");
                return ;
                break;
            case 'N':
            case 'n':
                printf("世の中そんなに甘くねぇよカス。\n");
                make();
                return ;
                break;
        }
    }
}
#endif

// 未完成
void quiet()
{
    printf("プログラムを終了するには、何か一つキーを押してください...");
    printf("\033[8mおっと、見つかってしまいましたか。\n");  // 8m is hidden. 0m is clear
    printf("hogehoge\n");
}

// 未完成
void endstep()
{
    printf("Endstep\n");
}

// 未完成
void help()
{
    printf("Help\n");
}




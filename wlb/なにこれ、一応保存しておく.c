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


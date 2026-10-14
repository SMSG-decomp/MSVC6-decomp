void __cdecl enc_set_environment(driver_ctx *ctx,char *program)

{
  char *pcVar1;
  char *work;
  char *buf;
  char *s;
  size_t len;
  char *s_2;
  char *s_3;
  size_t len_2;
  char *cl_env;
  char *t;
  int n;
  char *s_4;
  char *t_2;
  char *p;
  int n_2;
  size_t len_3;
  size_t len_4;
  int m;
  size_t sVar2;
  int m_2;
  char *t_4;
  char *p_2;
  int n_4;
  char *p_3;
  char *q;
  char *q_2;
  char *p_4;
  int iVar3;
  int n_3;
  cl_optrec *opt_3;
  cl_optrec *opt_2;
  cl_optrec *opt;
  char *cwd_env;
  char *pdb_env;
  char *t_3;
  
  cwd_env = (char *)0x0;
  pdb_env = (char *)0x0;
  work = xmalloc(0x400);
  buf = xmalloc(0x400);
  s = _getcwd(work,0x400);
  if (s != (char *)0x0) {
    len = strlen(work);
    cwd_env = xmalloc(len + 9);
    s_2 = strcpy_end(cwd_env,"ENC_CWD=");
    strcpy_end(s_2,work);
  }
  s_3 = program_path();
  len_2 = strlen(s_3);
  cl_env = xmalloc(len_2 + 8);
  t = strcpy_end(cl_env,"ENC_CL=");
  strcpy_end(t,s_3);
  n = action_expand_length("%f",ctx);
  s_4 = xmalloc(n + 9);
  t_2 = strcpy_end(s_4,"ENC_SRC=");
  p = action_expand_percent(work,"%f",ctx);
  strcpy_end(t_2,p);
  opt_3 = ctx->user_options;
  do {
    if (opt_3 == (cl_optrec *)0x0) {
LAB_00404a3b:
      n_3 = 9;
      for (opt_2 = ctx->user_options; opt_2 != (cl_optrec *)0x0; opt_2 = opt_2->next) {
        if (((opt_2->flags & 0x21) != 1) && (m = strcmp(opt_2->name,"ZX"), m != 0)) {
          sVar2 = strlen(opt_2->name);
          n_3 = n_3 + 2 + sVar2;
          pcVar1 = opt_2->value;
          if (pcVar1 != (char *)0x0) {
            if ((opt_2->flags & 0x20) == 0) {
              m_2 = quoted_length(pcVar1);
            }
            else {
              m_2 = action_expand_length(pcVar1,ctx);
            }
            n_3 = n_3 + m_2;
          }
        }
      }
      if (g_bt_type == (char *)0x0) {
        n_3 = n_3 + 4;
      }
      t_4 = xmalloc(n_3 + 3);
      p_2 = strcpy_end(t_4,"ENC_CMD=");
      for (opt = ctx->user_options; opt != (cl_optrec *)0x0; opt = opt->next) {
        if (((opt->flags & 0x21) != 1) && (n_4 = strcmp(opt->name,"ZX"), n_4 != 0)) {
          p_3 = strcpy_end(p_2,"-");
          q = strcpy_end(p_3,opt->name);
          pcVar1 = opt->value;
          if (pcVar1 != (char *)0x0) {
            if ((opt->flags & 0x20) == 0) {
              quote_argument(buf,pcVar1);
              q = strcpy_end(q,buf);
            }
            else {
              action_expand_percent(buf,pcVar1,ctx);
              quote_argument(work,buf);
              q = strcpy_end(q,work);
            }
          }
          p_2 = strcpy_end(q," ");
        }
      }
      if (g_bt_type == (char *)0x0) {
        q_2 = "-TP";
        if (ctx->file->type == 0) {
          q_2 = "-TC";
        }
        p_4 = strcpy_end(p_2,q_2);
        p_2 = strcpy_end(p_4," ");
      }
      strcpy_end(p_2,"-X");
      if (g_show_commands != 0) {
        if (cwd_env != (char *)0x0) {
          msg_write(2,"%s\n",cwd_env);
        }
        if (cl_env != (char *)0x0) {
          msg_write(2,"%s\n",cl_env);
        }
        if (s_4 != (char *)0x0) {
          msg_write(2,"%s\n",s_4);
        }
        if (pdb_env != (char *)0x0) {
          msg_write(2,"%s\n",pdb_env);
        }
        if (t_4 != (char *)0x0) {
          msg_write(2,"%s\n",t_4);
        }
      }
      if ((g_Bz_no_run == 0) &&
         (((((cwd_env != (char *)0x0 && (iVar3 = _putenv(cwd_env), iVar3 != 0)) ||
            (iVar3 = _putenv(cl_env), iVar3 != 0)) ||
           ((iVar3 = _putenv(s_4), iVar3 != 0 ||
            ((pdb_env != (char *)0x0 && (iVar3 = _putenv(pdb_env), iVar3 != 0)))))) ||
          (iVar3 = _putenv(t_4), iVar3 != 0)))) {
        cl_error(0x7ed,program);
      }
      xfree(t_4);
      xfree(pdb_env);
      xfree(s_4);
      xfree(cl_env);
      xfree(cwd_env);
      xfree(buf);
      xfree(work);
      return;
    }
    if (((opt_3->flags & 0x21) != 1) && (n_2 = strcmp(opt_3->name,"Fd"), n_2 == 0)) {
      strcpy(g_scratch,"ENC_PDB=");
      if (opt_3->value == (char *)0x0) {
        sVar2 = strlen(g_scratch);
        path_full(g_scratch + sVar2,"vc60",0x400 - sVar2);
      }
      else {
        strcat(g_scratch,opt_3->value);
      }
      t_3 = "vc60";
      len_3 = strlen("ENC_PDB=");
      path_set_default_extension("pdb",g_scratch + len_3,t_3);
      len_4 = strlen(g_scratch);
      pdb_env = xmalloc(len_4 + 1);
      strcpy(pdb_env,g_scratch);
      goto LAB_00404a3b;
    }
    opt_3 = opt_3->next;
  } while( true );
}


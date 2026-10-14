void __cdecl pass_set_driver_vars(driver_ctx *ctx)

{
  optrec *opt;
  bool bVar1;
  int rc;
  int rc_2;
  uint kind;
  char *s_2;
  cl_drvvar_target *target;
  char value [512];
  char *s;
  
  opt = ctx->pass_options;
  do {
    if (opt == (optrec *)0x0) {
      g_first_var_pass = 0;
      return;
    }
    rc = option_goes_to_pass(opt,g_passes);
    if (rc != 0) {
      bVar1 = false;
      target = (cl_drvvar_target *)&g_driver_vars[0].target;
      do {
        s = (char *)target[-2].flag;
        if (s == (char *)0x0) break;
        if ((*opt->name == *s) && (rc_2 = strcmp(opt->name,s), rc_2 == 0)) {
          bVar1 = true;
          if ((((uint)target[-1].flag & 8) == 0) || (g_first_var_pass != 0)) {
            kind = (uint)target[-1].flag & 7;
            if (kind == 1) {
              *target->flag = 1;
            }
            else if (kind == 2) {
              *target->flag = 0;
            }
            else if (kind == 3) {
              if (opt->value != (char *)0x0) {
                action_expand_percent(value,opt->value,ctx);
                if (*target->string != (char *)0x0) {
                  xfree(*target->string);
                }
                s_2 = xstrdup(value);
                *target->string = s_2;
              }
            }
            else if (kind == 4) {
              (*target->handler)(opt);
            }
          }
        }
        target = target + 3;
      } while (!bVar1);
    }
    opt = opt->next;
  } while( true );
}


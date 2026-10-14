void __cdecl options_check_requirements(void)

{
  optrec *opt;
  uchar *reqs;
  uchar *next;
  optrec *alts;
  int met;
  char *switch_text;
  char *alt_text;
  char *sep_text;
  optrec *pattern;
  optrec *list;
  uchar *group;
  UINT id;
  cl_optrec *alt;
  optdesc *desc;
  
  for (opt = g_driver_ctx_ptr->user_options; opt != (optrec *)0x0; opt = opt->next) {
    desc = (opt->src).desc;
    if (((desc != (optdesc *)0x0) && (desc->handler != (cl_opt_handler)0x0)) &&
       (desc->actions != (char *)0x0)) {
      reqs = (uchar *)xstrdup((char *)desc->handler);
      group = reqs;
      do {
        next = _mbschr(group,0x3b);
        if (next != (uchar *)0x0) {
          *next = '\0';
          next = next + 1;
        }
        alts = action_parse_list((char *)group,opt);
        met = optrec_list_any_match(g_driver_ctx_ptr->user_options,alts);
        group = next;
        if (met == 0) {
          if ((opt->flags & 1) == 0) {
            switch_text = xmalloc(0x50);
            alt_text = xmalloc(0x50);
            *switch_text = '/';
            *alt_text = '\0';
            strcpy(switch_text + 1,opt->name);
            for (alt = alts; alt != (cl_optrec *)0x0; alt = alt->next) {
              if (alt != alts) {
                if (alt->next == (cl_optrec *)0x0) {
                  id = 0x141;
                }
                else {
                  id = 0x140;
                }
                sep_text = load_message(id);
                strcat(alt_text,sep_text);
              }
              strcat(alt_text,"/");
              strcat(alt_text,alt->name);
            }
            cl_warning(0xfa7,switch_text,alt_text);
            xfree(alt_text);
            xfree(switch_text);
          }
          pattern = action_parse_list(desc->actions,opt);
          list = optrec_list_extract_matching
                           (&g_driver_ctx_ptr->pass_options,pattern,(optrec **)0x0);
          optrec_list_free(list);
          optrec_list_free(pattern);
          group = (uchar *)0x0;
        }
        optrec_list_free(alts);
      } while (group != (uchar *)0x0);
      xfree(reqs);
    }
  }
  return;
}


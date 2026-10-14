void __cdecl drv_LD_build_dll(optrec *r)

{
  cl_srcfile *f;
  optrec *opt;
  optrec *pattern;
  optrec *list;
  
  if (g_LD_enabled != 0) {
    g_LD_enabled = 1;
    g_dll = 1;
    for (f = g_driver_ctx_ptr->files; f != (cl_srcfile *)0x0; f = f->next) {
      if (f->type == 7) {
        opt = optrec_new("implib\\:",(char *)0x0,(char *)0x0,'\0');
        pattern = action_parse_list("=implib\\::?",opt);
        list = optrec_list_extract_matching(&g_driver_ctx_ptr->pass_options,pattern,(optrec **)0x0);
        optrec_list_free(list);
        optrec_free(opt);
        optrec_list_free(pattern);
        return;
      }
    }
  }
  return;
}


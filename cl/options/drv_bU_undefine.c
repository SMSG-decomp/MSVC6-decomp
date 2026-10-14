void __cdecl drv_bU_undefine(optrec *r)

{
  optrec *pattern;
  optrec *list;
  optrec *user;
  cl_optrec *rec;
  cl_u8 *refcount;
  
  pattern = action_parse_list("=D:*,=D:*=?",r);
  list = optrec_list_extract_matching(&g_driver_ctx_ptr->pass_options,pattern,(optrec **)0x0);
  for (rec = list; rec != (cl_optrec *)0x0; rec = rec->next) {
    if ((rec->flags & 1) == 0) {
      refcount = &((rec->src).owner)->refcount;
      *refcount = *refcount + 0xff;
      if (((rec->src).owner)->refcount == '\0') {
        user = list_unlink(&g_driver_ctx_ptr->user_options,(rec->src).owner);
        optrec_free(user);
      }
    }
  }
  optrec_list_free(list);
  optrec_list_free(pattern);
  return;
}


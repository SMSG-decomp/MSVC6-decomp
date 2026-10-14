void __cdecl drv_bu_undefine_all(optrec *r)

{
  int diff;
  optrec *rec;
  cl_optrec *next;
  optrec *rec_2;
  
  if (g_predefines_live != 0) {
    g_predefines_live = 0;
    next = g_driver_ctx_ptr->pass_options;
    while (rec_2 = next, rec_2 != (optrec *)0x0) {
      next = rec_2->next;
      if (((rec_2->flags & 1) != 0) && (diff = strcmp(rec_2->name,"D"), diff == 0)) {
        rec = list_unlink(&g_driver_ctx_ptr->pass_options,rec_2);
        optrec_free(rec);
      }
    }
  }
  return;
}


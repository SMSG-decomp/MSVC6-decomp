void __cdecl il_files_delete(int after_file)

{
  cl_ctx *drv;
  int suffix_index;
  cl_compile_node *n;
  int *per_file;
  cl_srcfile *file;
  int *next_suffix;
  
  if ((g_keep_il == 0) && (g_driver_ctx_ptr->temp_prefix != (char *)0x0)) {
    file = g_driver_ctx_ptr->file;
    suffix_index = 0;
    per_file = &g_il_temp_suffixes[0].per_file;
    drv = g_driver_ctx_ptr;
    do {
      if (after_file == 0) {
        if (*per_file == 0) {
          drv->file = (cl_srcfile *)0x0;
          goto LAB_00405a3c;
        }
        if (file != (cl_srcfile *)0x0) {
          n = drv->batch;
          if (n == (cl_compile_node *)0x0) {
            drv->file = file;
            goto LAB_00405a3c;
          }
          do {
            drv->file = n->file;
            il_file_delete(suffix_index);
            n = n->next;
            drv = g_driver_ctx_ptr;
          } while (n != (cl_compile_node *)0x0);
        }
      }
      else {
        if (*per_file == 0) goto LAB_00405a48;
LAB_00405a3c:
        il_file_delete(suffix_index);
        drv = g_driver_ctx_ptr;
      }
LAB_00405a48:
      suffix_index = suffix_index + 1;
      next_suffix = per_file + 1;
      per_file = per_file + 2;
    } while (*next_suffix != 0);
    drv->file = file;
  }
  return;
}


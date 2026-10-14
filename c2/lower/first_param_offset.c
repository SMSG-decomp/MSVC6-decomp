uint32_t first_param_offset(void)

{
  if (((g_cur_func_sym->attrs & 2) == 0) &&
     (((g_cur_func_sym->attrs & 1) != 0 || ((int)g_code_pointer_size < 9)))) {
    return 8;
  }
  return 0xc;
}


uint __cdecl il_function_option_word(void)

{
  uint uVar1;
  char **check;
  uint uVar2;
  
  uVar1 = 0;
  uVar2 = 0x80000000;
  check = &g_option_flag_pointers;
  do {
    if ((*check != (char *)0x0) && (**check != '\0')) {
      uVar1 = uVar1 | uVar2;
    }
    check = check + 1;
    uVar2 = uVar2 >> 1;
  } while ((int)check < 0x104d27c0);
  if ((g_current_function != (c1_symbol *)0x0) &&
     (((g_current_function->storage & 0x10) != 0 ||
      (((g_current_function->name->flags & 0x40000000) != 0 &&
       (g_current_function->scope_index == 0)))))) {
    uVar1 = uVar1 | 0x100;
  }
  return uVar1;
}


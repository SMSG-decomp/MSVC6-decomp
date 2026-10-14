wchar_t * __cdecl import_param_name(int index,wchar_t **names)

{
  wchar_t *pwVar1;
  
  pwVar1 = names[index];
  if (pwVar1 == (wchar_t *)0x0) {
    swprintf((wchar_t *)&g_import_arg_name_buffer,0x104ce310,(wchar_t *)index);
    pwVar1 = (wchar_t *)&g_import_arg_name_buffer;
  }
  return pwVar1;
}


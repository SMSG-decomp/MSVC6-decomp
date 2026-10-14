int __cdecl il_key_is_global_helper_function(int key)

{
  if ((key != 0) && (key == g_global_helper_key)) {
    return 1;
  }
  return 0;
}


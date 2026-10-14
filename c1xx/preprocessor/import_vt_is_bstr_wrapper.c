byte __cdecl import_vt_is_bstr_wrapper(short vt)

{
  if ((vt == 8) && (g_import_raw_native_types == 0)) {
    return 1;
  }
  return 0;
}


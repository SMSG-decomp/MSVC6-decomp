byte __cdecl import_get_ref_type_info(void *typeinfo,uint hreftype,void **result)

{
  int err;
  
  err = (**(code **)(*(int *)typeinfo + 0x38))(typeinfo,hreftype,result);
  if (err < 0) {
    if (err != -0x7ffd63b6) {
      diag_fatal_file(err,0x54,0x166,g_import_file_as_written);
    }
    if (g_import_missing_typelib_reported == 0) {
      g_import_missing_typelib_reported = 1;
      diag_error(0x304,"__missing_type__");
    }
    return 0;
  }
  return 1;
}


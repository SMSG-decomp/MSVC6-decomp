fe_name * __cdecl guid_format_symbol_name(c1_guid *guid)

{
  fe_name *pfVar1;
  
  pfVar1 = guid_format("_GUID_%08x_%04x_%04x_%02x%02x_%02x%02x%02x%02x%02x%02x",guid);
  return pfVar1;
}


void * __cdecl guid_format_registry(void *guid)

{
  void *pvVar1;
  
  pvVar1 = guid_format("%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",guid);
  return pvVar1;
}


byte __cdecl os_is_windows_nt(void)

{
  DWORD DVar1;
  
  DVar1 = GetVersion();
  return ~(byte)(DVar1 >> 0x1f) & 1;
}


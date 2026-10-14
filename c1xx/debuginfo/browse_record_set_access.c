void __cdecl browse_record_set_access(ushort *attrs,char access)

{
  if (access == '\x01') {
    *attrs = *attrs & 0xf7bf | 0x400;
    return;
  }
  if (access != '\x02') {
    *attrs = *attrs & 0xf3ff | 0x40;
    return;
  }
  *attrs = *attrs & 0xfbbf | 0x800;
  return;
}


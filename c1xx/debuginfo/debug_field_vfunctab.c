uint __cdecl debug_field_vfunctab(int pass,int member,int sym,ushort *out)

{
  uint uVar1;
  
  if (pass == 1) {
    uVar1 = debug_type_record_vtshape((c1_symbol *)sym);
    uVar1 = debug_type_record_pointer(*(c1_type **)(member + 0x14),uVar1);
    *g_debug_index_queue = uVar1;
    g_debug_index_queue = g_debug_index_queue + 1;
    return (uint)g_debug_index_queue & 0xffff0000;
  }
  *out = 0x1409;
  out[1] = 0;
  uVar1 = *g_debug_index_queue;
  g_debug_index_queue = g_debug_index_queue + 1;
  *(uint *)(out + 2) = uVar1;
  return CONCAT22((short)((uint)out >> 0x10),8);
}


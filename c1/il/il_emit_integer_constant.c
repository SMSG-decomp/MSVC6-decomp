void __cdecl il_emit_integer_constant(uint lo,int hi,int size)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if ((hi < -1) || ((((hi < 0 && (lo < 0xffffff81)) || (0 < hi)) || ((-1 < hi && (0x7f < lo)))))) {
    if ((g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 2) &&
       (iVar2 = il_buffer_grow(&g_il_ex.bytes,2), iVar2 == 0)) {
      bVar1 = 0;
    }
    else {
      bVar1 = 1;
    }
    g_il_ex.open = g_il_ex.open & bVar1;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.pbEnd = 0x80;
      g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
    }
    if ((g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 5) &&
       (iVar2 = il_buffer_grow(&g_il_ex.bytes,5), iVar2 == 0)) {
      bVar1 = 0;
    }
    else {
      bVar1 = 1;
    }
    g_il_ex.open = g_il_ex.open & bVar1;
    if (g_il_ex.open != 0) {
      *(uint *)g_il_ex.bytes.pbEnd = lo;
      g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 4;
    }
    iVar2 = ((int)(size + (size >> 0x1f & 3U)) >> 2) + -1;
    if (0 < iVar2) {
      piVar4 = &hi;
      do {
        if ((g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 5) &&
           (iVar3 = il_buffer_grow(&g_il_ex.bytes,5), iVar3 == 0)) {
          bVar1 = 0;
        }
        else {
          bVar1 = 1;
        }
        g_il_ex.open = g_il_ex.open & bVar1;
        if (g_il_ex.open != 0) {
          *(int *)g_il_ex.bytes.pbEnd = *piVar4;
          g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 4;
        }
        piVar4 = piVar4 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  else {
    if ((g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 2) &&
       (iVar2 = il_buffer_grow(&g_il_ex.bytes,2), iVar2 == 0)) {
      bVar1 = 0;
    }
    else {
      bVar1 = 1;
    }
    g_il_ex.open = g_il_ex.open & bVar1;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.pbEnd = (uchar)lo;
      g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
      return;
    }
  }
  return;
}


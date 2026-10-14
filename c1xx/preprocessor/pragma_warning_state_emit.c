void __cdecl pragma_warning_state_emit(byte code)

{
  c1_u8 cVar1;
  bool bVar2;
  c1_u8 *pcVar3;
  byte bVar4;
  int iVar5;
  short sVar6;
  uint uVar7;
  
  bVar2 = false;
  uVar7 = g_warning_state_emit_min;
  if (g_warning_state_emit_min <= g_warning_state_emit_max) {
    do {
      cVar1 = g_warning_state->state[uVar7];
      if (cVar1 != '\0') {
        if (!bVar2) {
          il_emit_byte_record('O');
          if ((g_il_ex.bytes.start + g_il_ex.bytes.size < g_il_ex.bytes.cur + 2) &&
             (iVar5 = il_buffer_grow(&g_il_ex.bytes,2), iVar5 == 0)) {
            bVar4 = 0;
          }
          else {
            bVar4 = 1;
          }
          g_il_ex.open = g_il_ex.open & bVar4;
          if (g_il_ex.open != 0) {
            *g_il_ex.bytes.cur = code;
            g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
          }
          bVar2 = true;
        }
        sVar6 = (short)uVar7 + -700;
        if ((g_il_ex.bytes.start + g_il_ex.bytes.size < g_il_ex.bytes.cur + 4) &&
           (iVar5 = il_buffer_grow(&g_il_ex.bytes,4), iVar5 == 0)) {
          bVar4 = 0;
        }
        else {
          bVar4 = 1;
        }
        g_il_ex.open = g_il_ex.open & bVar4;
        if ((g_il_ex.open != 0) &&
           (iVar5 = il_buffer_put_byte7(&g_il_ex,(int)sVar6), (char)iVar5 == '\0')) {
          *g_il_ex.bytes.cur = 0x80;
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
          *(short *)g_il_ex.bytes.cur = sVar6;
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 2;
        }
        if ((g_il_ex.bytes.start + g_il_ex.bytes.size < g_il_ex.bytes.cur + 2) &&
           (iVar5 = il_buffer_grow(&g_il_ex.bytes,2), iVar5 == 0)) {
          bVar4 = 0;
        }
        else {
          bVar4 = 1;
        }
        g_il_ex.open = g_il_ex.open & bVar4;
        if (g_il_ex.open != 0) {
          *g_il_ex.bytes.cur = cVar1;
          g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
        }
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 <= g_warning_state_emit_max);
    if (bVar2) {
      if ((g_il_ex.bytes.start + g_il_ex.bytes.size < g_il_ex.bytes.cur + 4) &&
         (iVar5 = il_buffer_grow(&g_il_ex.bytes,4), iVar5 == 0)) {
        bVar4 = 0;
      }
      else {
        bVar4 = 1;
      }
      g_il_ex.open = g_il_ex.open & bVar4;
      if (g_il_ex.open != 0) {
        *g_il_ex.bytes.cur = 0x80;
        g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
        pcVar3 = g_il_ex.bytes.cur + 1;
        g_il_ex.bytes.cur[0] = 0xff;
        *pcVar3 = 0xff;
        g_il_ex.bytes.cur = g_il_ex.bytes.cur + 2;
      }
    }
  }
  return;
}


char __thiscall
file_tell_seek_or_fatal(c1_source_tracker_iface *iface,int n,uint *signature,int *count)

{
  uchar *puVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  long lVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  
  iVar2 = lex_input_bytes_left();
  iVar7 = n;
  if (iVar2 <= n) {
    iVar7 = lex_input_bytes_left();
  }
  pvVar3 = lex_source_input_ptr();
  uVar4 = SigForPbCb(pvVar3,iVar7,0xffffffff);
  iVar2 = n - iVar7;
  *signature = uVar4;
  *count = iVar7;
  if (iVar2 == 0) {
    iVar2 = lex_input_bytes_left();
    if ((iVar7 == iVar2) && (uVar8 = file_current_at_eof(), (char)uVar8 != '\0')) {
      uVar4 = SigForPbCb(&g_source_signature_eof_byte,1,uVar4);
      *signature = uVar4;
    }
  }
  else {
    lVar5 = file_tell_current_source();
    if (lVar5 == -1) {
      pcVar6 = pp_position_file_name(&g_token_position);
      diag_fatal_file_errno(0x57,(-(uint)(g_source_tracker_depth != 0) & 2) + 0x155,pcVar6);
    }
    puVar1 = g_arenas[1].cur;
    if (g_source_signature_buffer == (c1_u8 *)0x0) {
      g_arenas[1].cur = g_arenas[1].cur + 0x7000;
      if (g_arenas[1].end < g_arenas[1].cur) {
        arena_grow(g_arenas + 1);
      }
      g_source_signature_buffer = puVar1;
    }
    do {
      iVar7 = file_read_source_block(g_source_signature_buffer);
      if (iVar7 == 0) {
        uVar4 = SigForPbCb(&g_source_signature_eof_byte,1,uVar4);
        *signature = uVar4;
        break;
      }
      uVar4 = SigForPbCb(g_source_signature_buffer,iVar7,uVar4);
      iVar2 = iVar2 - iVar7;
      *signature = uVar4;
      *count = *count + iVar7;
    } while (iVar2 != 0);
    lVar5 = file_seek_current_source(lVar5);
    if (lVar5 == -1) {
      pcVar6 = pp_position_file_name(&g_token_position);
      diag_fatal_file_errno(0x56,(-(uint)(g_source_tracker_depth != 0) & 2) + 0x155,pcVar6);
      return '\x01';
    }
  }
  return '\x01';
}


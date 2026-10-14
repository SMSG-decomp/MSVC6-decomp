char __thiscall
file_tell_seek_or_fatal(c1xx_source_tracker_iface *iface,int n,uint *signature,int *count)

{
  c1_u8 *pcVar1;
  c1_u8 cVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  long lVar6;
  char *pcVar7;
  int iVar8;
  
  iVar3 = lex_input_bytes_left();
  iVar8 = n;
  if (iVar3 <= n) {
    iVar8 = lex_input_bytes_left();
  }
  pvVar4 = lex_source_input_ptr();
  uVar5 = SigForPbCb(pvVar4,iVar8,0xffffffff);
  iVar3 = n - iVar8;
  *signature = uVar5;
  *count = iVar8;
  if (iVar3 == 0) {
    iVar3 = lex_input_bytes_left();
    if ((iVar8 == iVar3) && (cVar2 = file_current_at_eof(), cVar2 != '\0')) {
      uVar5 = SigForPbCb(&g_source_signature_eof_byte,1,uVar5);
      *signature = uVar5;
    }
  }
  else {
    lVar6 = file_tell_current_source();
    if (lVar6 == -1) {
      pcVar7 = pp_position_file_name(&g_token_position);
      diag_fatal_file_errno(0x57,(-(uint)(g_source_tracker_depth != 0) & 2) + 0x155,pcVar7);
    }
    pcVar1 = g_arenas[1].cur;
    if (g_source_signature_buffer == (c1_u8 *)0x0) {
      g_arenas[1].cur = g_arenas[1].cur + 0x7000;
      if (g_arenas[1].end < g_arenas[1].cur) {
        arena_grow(g_arenas + 1);
      }
      g_source_signature_buffer = pcVar1;
    }
    do {
      iVar8 = file_read_source_block(g_source_signature_buffer);
      if (iVar8 == 0) {
        uVar5 = SigForPbCb(&g_source_signature_eof_byte,1,uVar5);
        *signature = uVar5;
        break;
      }
      uVar5 = SigForPbCb(g_source_signature_buffer,iVar8,uVar5);
      iVar3 = iVar3 - iVar8;
      *signature = uVar5;
      *count = *count + iVar8;
    } while (iVar3 != 0);
    lVar6 = file_seek_current_source(lVar6);
    if (lVar6 == -1) {
      pcVar7 = pp_position_file_name(&g_token_position);
      diag_fatal_file_errno(0x56,(-(uint)(g_source_tracker_depth != 0) & 2) + 0x155,pcVar7);
      return '\x01';
    }
  }
  return '\x01';
}


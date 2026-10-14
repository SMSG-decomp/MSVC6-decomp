void __cdecl func_flow_state_note_31(void)

{
  int iVar1;
  uint *puVar2;
  uint flow_rec [8];
  
  puVar2 = flow_rec;
  flow_rec[0] = 0x31;
  for (iVar1 = 7; puVar2 = puVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
  }
  if (g_flow_state_abandoned == '\0') {
    flow_rec[6] = 0;
    flow_rec[7] = 0;
    flow_rec[5] = 0;
    flow_rec[1]._0_1_ = (byte)flow_rec[1] & 0xe8;
    flow_rec[4] = (uint)g_flow_switch_record;
    func_check_flow_state_complexity((c1_u8 *)flow_rec,0x20);
    g_flow_switch_record = g_flow_state_top;
    stmt_switch_selector_begin_flow_state();
  }
  return;
}


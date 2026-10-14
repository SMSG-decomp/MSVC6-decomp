void __fastcall push_warning_state(short warning,short state)

{
  if (warning < 700) {
    warning = warning + 700;
  }
  if (g_warning_state_count < 0x32) {
    g_warning_state_table[g_warning_state_count].warning = warning;
    g_warning_state_table[g_warning_state_count].state = state;
    g_warning_state_count = g_warning_state_count + 1;
    return;
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\Common\\error.c",0x8c);
}


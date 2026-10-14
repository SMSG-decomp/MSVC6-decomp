void __cdecl func_flow_state_release_innermost(int kind)

{
  c1_flow_state *rec;
  
  rec = func_flow_state_find(g_flow_state_top,kind,'\0');
  if (rec != (c1_flow_state *)0x0) {
    func_flow_state_release(rec);
  }
  return;
}


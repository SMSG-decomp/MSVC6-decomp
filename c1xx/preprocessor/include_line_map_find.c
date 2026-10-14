c1_line_map_row * __thiscall include_line_map_find(c1_line_map_state *state,int position)

{
  c1_line_map_row *pcVar1;
  
  pcVar1 = &state->cached;
  if (pcVar1->position != position) {
    pcVar1 = pp_line_map_find_entry(&state->map,position);
  }
  return pcVar1;
}


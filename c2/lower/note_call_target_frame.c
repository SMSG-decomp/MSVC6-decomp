void __fastcall note_call_target_frame(c2_tuple *call)

{
  if (g_fp_lower_depth != -1) {
    x87_spill_stack_entries(call,g_fp_lower_depth + 1,0);
  }
  return;
}


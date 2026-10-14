char __thiscall pdb_file_stack_top_object(c1_mre_tracker *tracker,c1_mre_file **out)

{
  c1_mre_file *pcVar1;
  
  *out = (c1_mre_file *)0x0;
  pcVar1 = tracker->current->file;
  if (pcVar1 != (c1_mre_file *)0x0) {
    *out = pcVar1;
    return '\x01';
  }
  return '\0';
}


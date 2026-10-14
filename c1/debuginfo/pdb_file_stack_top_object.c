char __thiscall pdb_file_stack_top_object(c1_pdb_source_file **stack,MREFile **out)

{
  *out = (MREFile *)0x0;
  if ((*stack)->object != (MREFile *)0x0) {
    *out = (*stack)->object;
    return '\x01';
  }
  return '\0';
}


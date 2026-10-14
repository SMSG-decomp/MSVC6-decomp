void ide_open_feedback_channel(void)

{
  c2_ide_feedback_channel *pcVar1;
  char *pcVar2;
  
  pcVar1 = arena_alloc(7,0x14);
  pcVar1->open = ide_feedback_noop;
  pcVar1->write = ide_feedback_write;
  pcVar1->ice = ide_feedback_ice;
  pcVar2 = arena_alloc(7,0x40);
  pcVar1->buffer = pcVar2;
  pcVar1->buffer_size = 0x40;
  g_ide_feedback_channel = pcVar1;
  g_ide_feedback_handle = (*pcVar1->open)();
  return;
}


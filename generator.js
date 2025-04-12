
Blockly.JavaScript['motor_on'] = function(block) {
  const port = block.getFieldValue('PORT');
  const speed = block.getFieldValue('SPEED');
  return `
<Block>
  <Type>motor_on</Type>
  <Port>${port}</Port>
  <Speed>${speed}</Speed>
</Block>`;
};

Blockly.JavaScript['wait'] = function(block) {
  const duration = block.getFieldValue('DURATION');
  return `
<Block>
  <Type>wait</Type>
  <Duration>${duration}</Duration>
</Block>`;
};

Blockly.JavaScript['motor_off'] = function(block) {
  const port = block.getFieldValue('PORT');
  return `
<Block>
  <Type>motor_off</Type>
  <Port>${port}</Port>
</Block>`;
};

Blockly.JavaScript.workspaceToCode = function(workspace) {
  const blocks = workspace.getTopBlocks(true);
  let code = '';
  for (const block of blocks) {
    code += Blockly.JavaScript.blockToCode(block);
  }

  const name = document.getElementById('projectName')?.value || "MyProgram";

  return `<Project>
  <Name>${name}</Name>
  <Blocks>
${code.trim()}
  </Blocks>
</Project>`;
};

Blockly.JavaScript['input_digital'] = function(block) {
  const port = block.getFieldValue('PORT');
  return [`<Input port="${port}"/>`, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['play_sound'] = function(block) {
  const sound = block.getFieldValue('SOUND');
  return `
<Block>
  <Type>play_sound</Type>
  <Sound>${sound}</Sound>
</Block>`;
};


Blockly.defineBlocksWithJsonArray([
  {
    "type": "motor_on",
    "message0": "Motoru aç %1 hız %2",
    "args0": [
      {
        "type": "field_dropdown",
        "name": "PORT",
        "options": [["M1", "M1"], ["M2", "M2"]]
      },
      {
        "type": "field_number",
        "name": "SPEED",
        "value": 100,
        "min": -100,
        "max": 100
      }
    ],
    "previousStatement": null,
    "nextStatement": null,
    "colour": 160
  },
  {
    "type": "wait",
    "message0": "%1 ms bekle",
    "args0": [
      {
        "type": "field_number",
        "name": "DURATION",
        "value": 1000
      }
    ],
    "previousStatement": null,
    "nextStatement": null,
    "colour": 230
  },
  {
    "type": "motor_off",
    "message0": "Motoru kapat %1",
    "args0": [
      {
        "type": "field_dropdown",
        "name": "PORT",
        "options": [["M1", "M1"], ["M2", "M2"]]
      }
    ],
    "previousStatement": null,
    "nextStatement": null,
    "colour": 160
  }
]);

Blockly.defineBlocksWithJsonArray([
  {
    "type": "input_digital",
    "message0": "Giriş oku %1",
    "args0": [
      {
        "type": "field_dropdown",
        "name": "PORT",
        "options": [["I1", "I1"], ["I2", "I2"], ["I3", "I3"], ["I4", "I4"]]
      }
    ],
    "output": "Boolean",
    "colour": 120
  }
]);

Blockly.defineBlocksWithJsonArray([
  {
    "type": "play_sound",
    "message0": "Ses çal %1",
    "args0": [
      {
        "type": "field_dropdown",
        "name": "SOUND",
        "options": [["Bip", "bip"], ["Uyarı", "alert"], ["Melodi", "melody"]]
      }
    ],
    "previousStatement": null,
    "nextStatement": null,
    "colour": 290
  }
]);

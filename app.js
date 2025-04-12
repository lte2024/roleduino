
async function sendViaBLE() {
  const code = Blockly.JavaScript.workspaceToCode(workspace);
  const projectName = document.getElementById('projectName')?.value || "MyProgram";

  const header = `<FILE>${projectName}.rpp</FILE>\n`;
  const fullData = header + code;

  const encoder = new TextEncoder();
  const data = encoder.encode(fullData);

  try {
    const device = await navigator.bluetooth.requestDevice({
      acceptAllDevices: true,
      optionalServices: ['0000ffe0-0000-1000-8000-00805f9b34fb']
    });

    const server = await device.gatt.connect();
    const service = await server.getPrimaryService('0000ffe0-0000-1000-8000-00805f9b34fb');
    const characteristic = await service.getCharacteristic('0000ffe1-0000-1000-8000-00805f9b34fb');

    const chunkSize = 20;
    for (let i = 0; i < data.length; i += chunkSize) {
      const chunk = data.slice(i, i + chunkSize);
      await characteristic.writeValue(chunk);
    }

    alert("BLE ile TXT Controller'a proje adıyla gönderildi ✅");
  } catch (err) {
    console.error("BLE hata:", err);
    alert("BLE bağlantısı başarısız ❌");
  }
}

async function generateRPP() {
  const code = Blockly.JavaScript.workspaceToCode(workspace);
  const projectName = document.getElementById('projectName')?.value || "MyProgram";

  const zip = new JSZip();
  zip.file(`${projectName}.rpp`, code);

  const blob = await zip.generateAsync({ type: "blob" });
  const url = URL.createObjectURL(blob);

  const a = document.createElement("a");
  a.href = url;
  a.download = `${projectName}.zip";
  a.click();

  URL.revokeObjectURL(url);
}
